using System;
using System.Collections.Generic;
using System.Linq;
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

namespace SEMES_CAR_GUI
{
    /// <summary>
    /// ErrorDialog.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class ErrorDialog : Window
    {
        public ErrorDialog(string errorMessage)
        {
            InitializeComponent();
            ErrorMessageTextBlock.Text = errorMessage; // 에러 메시지를 TextBlock에 설정
        }

        private void OkButton_Click(object sender, RoutedEventArgs e)
        {
            this.Close(); // OK 버튼 클릭 시 다이얼로그 닫기
        }
    }
}
