using System;
using System.Net.Sockets;
using System.Text;
using System.Windows;

namespace CarManufactureApp
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            SubmitButton.Click += SubmitButton_Click;
        }

        // 제출 버튼 클릭 시
        private void SubmitButton_Click(object sender, RoutedEventArgs e)
        {
            // 선택된 옵션 인덱스를 서버로 전송
            var selectedOptions = GetSelectedOptions();
            string selectedOptionsString = string.Join(",", selectedOptions);

            // 서버로 옵션 전송
            string result = SendOptionsToServer(selectedOptionsString);

            // 결과 텍스트에 표시
            ResultTextBlock.Text = result;
        }

        // 선택된 옵션을 읽어들여 인덱스로 변환
        private string[] GetSelectedOptions()
        {
            var selectedOptions = new System.Collections.Generic.List<string>();

            // 차량 타입 선택
            if (SedanRadioButton.IsChecked == true) selectedOptions.Add("1"); // Sedan - 인덱스 1
            else if (SUVRadioButton.IsChecked == true) selectedOptions.Add("2"); // SUV - 인덱스 2
            else if (TruckRadioButton.IsChecked == true) selectedOptions.Add("3"); // Truck - 인덱스 3

            // 엔진 타입 선택
            if (GMRadioButton.IsChecked == true) selectedOptions.Add("1"); // GM - 인덱스 1
            else if (ToyotaRadioButton.IsChecked == true) selectedOptions.Add("2"); // Toyota - 인덱스 2
            else if (WiaRadioButton.IsChecked == true) selectedOptions.Add("3"); // WIA - 인덱스 3

            // 브레이크 타입 선택
            if (MandoRadioButton.IsChecked == true) selectedOptions.Add("1"); // MANDO - 인덱스 1
            else if (ContinentalRadioButton.IsChecked == true) selectedOptions.Add("2"); // Continental - 인덱스 2
            else if (BoschRadioButton.IsChecked == true) selectedOptions.Add("3"); // Bosch - 인덱스 3

            // 스티어링 타입 선택
            if (BoschSteeringRadioButton.IsChecked == true) selectedOptions.Add("1"); // Bosch - 인덱스 1
            else if (MobisSteeringRadioButton.IsChecked == true) selectedOptions.Add("2"); // Mobis - 인덱스 2

            return selectedOptions.ToArray();
        }

        // 전체 초기화 버튼 클릭 시
        private void ResetButton_Click(object sender, RoutedEventArgs e)
        {
            // 모든 라디오 버튼 선택 해제
            SedanRadioButton.IsChecked = false;
            SUVRadioButton.IsChecked = false;
            TruckRadioButton.IsChecked = false;

            GMRadioButton.IsChecked = false;
            ToyotaRadioButton.IsChecked = false;
            WiaRadioButton.IsChecked = false;

            MandoRadioButton.IsChecked = false;
            ContinentalRadioButton.IsChecked = false;
            BoschRadioButton.IsChecked = false;

            BoschSteeringRadioButton.IsChecked = false;
            MobisSteeringRadioButton.IsChecked = false;

            // 결과 텍스트 초기화
            ResultTextBlock.Text = string.Empty;
        }



        private string SendOptionsToServer(string selectedOptions)
        {
            try
            {
                // 서버 IP와 포트 설정
                string serverIp = "127.0.0.1"; // 예시 IP, 실제 서버 IP로 변경
                int serverPort = 8080;

                // TCP 소켓을 사용하여 서버와 연결
                using (TcpClient client = new TcpClient(serverIp, serverPort))
                {
                    NetworkStream stream = client.GetStream();
                    byte[] dataToSend = Encoding.UTF8.GetBytes(selectedOptions);
                    stream.Write(dataToSend, 0, dataToSend.Length);

                    // 서버로부터 응답 받기
                    byte[] buffer = new byte[1024];
                    int bytesRead = stream.Read(buffer, 0, buffer.Length);
                    string response = Encoding.UTF8.GetString(buffer, 0, bytesRead);

                    return response;
                }
            }
            catch (Exception ex)
            {
                return $"Error: {ex.Message}";
            }
        }

        
    }
}
