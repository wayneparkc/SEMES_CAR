using System;
using System.Net.Sockets;
using System.Text;
using System.Windows;
using System.Threading.Tasks;
using System.Windows.Controls.Primitives;
using System.Windows.Controls;

namespace SEMES_CAR_GUI
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            SubmitButton.Click += SubmitButton_Click;
            ResetButton.Click += ResetButton_Click;

            // 각 라디오 버튼에 Checked 및 Unchecked 이벤트 핸들러 추가
            SedanRadioButton.Checked += Option_Checked;
            SUVRadioButton.Checked += Option_Checked;
            TruckRadioButton.Checked += Option_Checked;

            GMRadioButton.Checked += Option_Checked;
            ToyotaRadioButton.Checked += Option_Checked;
            WiaRadioButton.Checked += Option_Checked;

            MandoRadioButton.Checked += Option_Checked;
            ContinentalRadioButton.Checked += Option_Checked;
            BoschRadioButton.Checked += Option_Checked;

            BoschSteeringRadioButton.Checked += Option_Checked;
            MobisSteeringRadioButton.Checked += Option_Checked;

            SedanRadioButton.Unchecked += Option_Unchecked;
            SUVRadioButton.Unchecked += Option_Unchecked;
            TruckRadioButton.Unchecked += Option_Unchecked;

            GMRadioButton.Unchecked += Option_Unchecked;
            ToyotaRadioButton.Unchecked += Option_Unchecked;
            WiaRadioButton.Unchecked += Option_Unchecked;

            MandoRadioButton.Unchecked += Option_Unchecked;
            ContinentalRadioButton.Unchecked += Option_Unchecked;
            BoschRadioButton.Unchecked += Option_Unchecked;

            BoschSteeringRadioButton.Unchecked += Option_Unchecked;
            MobisSteeringRadioButton.Unchecked += Option_Unchecked;
        }

        // 제출 버튼 클릭 시
        private async void SubmitButton_Click(object sender, RoutedEventArgs e)
        {
            var selectedOptions = GetSelectedOptions();
            string selectedOptionsString = string.Join(",", selectedOptions);

            // 서버로 옵션 전송 (비동기)
            string result = await SendOptionsToServerAsync(selectedOptionsString);

            // 서버 응답 확인
            if (result.StartsWith("Su"))
            {
                // 성공 처리: ResultPage로 선택한 옵션을 전달
                string successMessage = result.Substring(2); // "Su" 이후의 메시지
                ResultWindow resultPage = new ResultWindow(successMessage, selectedOptionsString);
                resultPage.Show();
                this.Close();
                //this.NavigationService.Navigate(resultPage); // ResultPage로 이동
            }
            else 
            {
                // 실패 처리: 에러 메시지 표시 후 옵션 초기화
                string errorMessage = result.Substring(2); // "Fa" 이후의 에러 메시지
                ErrorDialog errorDialog = new ErrorDialog(errorMessage);
                errorDialog.ShowDialog(); // Modal로 다이얼로그 띄우기
                // 옵션 초기화
                ResetButton_Click(sender, e);  // Reset all options
            }
            
           
        }


        // 선택된 옵션을 읽어들여 인덱스로 변환
        private string[] GetSelectedOptions()
        {
            var selectedOptions = new System.Collections.Generic.List<string>();

            if (SedanRadioButton.IsChecked == true) selectedOptions.Add("1");
            else if (SUVRadioButton.IsChecked == true) selectedOptions.Add("2");
            else if (TruckRadioButton.IsChecked == true) selectedOptions.Add("3");

            if (GMRadioButton.IsChecked == true) selectedOptions.Add("1");
            else if (ToyotaRadioButton.IsChecked == true) selectedOptions.Add("2");
            else if (WiaRadioButton.IsChecked == true) selectedOptions.Add("3");

            if (MandoRadioButton.IsChecked == true) selectedOptions.Add("1");
            else if (ContinentalRadioButton.IsChecked == true) selectedOptions.Add("2");
            else if (BoschRadioButton.IsChecked == true) selectedOptions.Add("3");

            if (BoschSteeringRadioButton.IsChecked == true) selectedOptions.Add("1");
            else if (MobisSteeringRadioButton.IsChecked == true) selectedOptions.Add("2");

            return selectedOptions.ToArray();
        }

        // 전체 초기화 버튼 클릭 시
        private void ResetButton_Click(object sender, RoutedEventArgs e)
        {
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

            ResultTextBlock.Text = string.Empty;

            // 리셋 시에도 SubmitButton 비활성화
            SubmitButton.IsEnabled = false;
        }

        // 서버에 비동기 방식으로 옵션을 전송하고 응답을 받음
        private async Task<string> SendOptionsToServerAsync(string selectedOptions)
        {
            try
            {
                string serverIp = "127.0.0.1"; // 실제 서버 IP로 변경
                int serverPort = 8080;

                using (TcpClient client = new TcpClient(serverIp, serverPort))
                {
                    NetworkStream stream = client.GetStream();
                    byte[] dataToSend = Encoding.UTF8.GetBytes(selectedOptions);

                    await stream.WriteAsync(dataToSend, 0, dataToSend.Length);  // 비동기 방식으로 데이터 전송

                    byte[] buffer = new byte[1024];
                    int bytesRead = await stream.ReadAsync(buffer, 0, buffer.Length);  // 비동기 방식으로 서버 응답 받기

                    string response = Encoding.UTF8.GetString(buffer, 0, bytesRead);
                    return response;
                }
            }
            catch (Exception ex)
            {
                return $"Error: {ex.Message}";
            }
        }

        // 옵션이 선택되었을 때 Submit 버튼 활성화 여부 체크
        private void Option_Checked(object sender, RoutedEventArgs e)
        {
            CheckSubmitButtonStatus();
        }

        // 옵션이 선택 해제되었을 때 Submit 버튼 활성화 여부 체크
        private void Option_Unchecked(object sender, RoutedEventArgs e)
        {
            CheckSubmitButtonStatus();
        }

        // 모든 옵션 그룹에 대해 선택 여부를 확인하고 Submit 버튼을 활성화하거나 비활성화
        private void CheckSubmitButtonStatus()
        {
            bool allOptionsSelected =
                (SedanRadioButton.IsChecked == true || SUVRadioButton.IsChecked == true || TruckRadioButton.IsChecked == true) &&
                (GMRadioButton.IsChecked == true || ToyotaRadioButton.IsChecked == true || WiaRadioButton.IsChecked == true) &&
                (MandoRadioButton.IsChecked == true || ContinentalRadioButton.IsChecked == true || BoschRadioButton.IsChecked == true) &&
                (BoschSteeringRadioButton.IsChecked == true || MobisSteeringRadioButton.IsChecked == true);

            SubmitButton.IsEnabled = allOptionsSelected; // 모든 옵션이 선택되었을 경우만 활성화
        }
    }
}
