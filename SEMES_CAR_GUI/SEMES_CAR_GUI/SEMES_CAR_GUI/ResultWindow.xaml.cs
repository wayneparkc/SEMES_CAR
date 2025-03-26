using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net.Sockets;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;


namespace SEMES_CAR_GUI {
    /// <summary>
    /// ResultWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class ResultWindow : Window {
        // 이미지 주소 배열
        string[] car_types = { "", "/assets/sedan.png", "/assets/suv.png", "/assets/truck.png" };
        string[] engines = { "", "/assets/gm.png", "/assets/toyota.png", "/assets/wia.png" };
        string[] breakSystems = { "", "/assets/mando.png", "/assets/continental.png", "/assets/bosch.png" };
        string[] steerSystems = { "", "/assets/bosch.png", "/assets/mobis.png" };
        
        public ResultWindow(string message, string options) {
            InitializeComponent();
            changeImg(options);
            GoFirstButton.Click += GoFirstButton_Click;
        }

        private void changeImg(string options) {
            int[] optionList = options.Split(',').Select(int.Parse).ToArray();
            carType.Source = new BitmapImage(new Uri(car_types[optionList[0]], UriKind.Relative));
            engine.Source = new BitmapImage(new Uri(engines[optionList[1]], UriKind.Relative));
            breakSystem.Source = new BitmapImage(new Uri(breakSystems[optionList[2]], UriKind.Relative));
            steerSystem.Source = new BitmapImage(new Uri(steerSystems[optionList[3]], UriKind.Relative));
        }

        private void GoFirstButton_Click(object sender, RoutedEventArgs e)
        {
            MainWindow mainWindow = new MainWindow();
            mainWindow.Show();
            this.Close();
        }


        //    private void StartSocketListener()
        //    {
        //        socketThread = new Thread(() =>
        //        {
        //            TcpListener listener = new TcpListener(IPAddress.Any, 12345); // 포트 12345에서 수신
        //            listener.Start();
        //            while (true)
        //            {
        //                using (TcpClient client = listener.AcceptTcpClient())
        //                using (NetworkStream stream = client.GetStream())
        //                {
        //                    byte[] buffer = new byte[1024];
        //                    int bytesRead = stream.Read(buffer, 0, buffer.Length);
        //                    string receivedData = Encoding.UTF8.GetString(buffer, 0, bytesRead).Trim();
        //                    UpdateCarType(receivedData);
        //                }
        //            }
        //        });
        //        socketThread.IsBackground = true;
        //        socketThread.Start();
        //    }

        //    private void UpdateCarType(string car)
        //    {
        //        Dispatcher.Invoke(() =>
        //        {
        //            int index = car switch
        //            {
        //                "sedan" => 1,
        //                "suv" => 2,
        //                "truck" => 3,
        //                _ => 0
        //            };

        //            if (index > 0)
        //            {
        //                carType.Source = new BitmapImage(new Uri(images[index], UriKind.Relative));
        //            }
        //        });
        //    }
        //}
    }
}
