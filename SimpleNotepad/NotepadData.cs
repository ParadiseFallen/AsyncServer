using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SimpleNotepad
{
    public class NotepadData: INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;
        public event Action<object, string> FileLoaded;

        private string _CurrentPatch = "";
        public string CurrentPatch { get { return _CurrentPatch; } set { _CurrentPatch = value; PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("CurrentPatch")); } } 

        private string _Data = "";
        public string Data { get { return _Data; } set { _Data = value; PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Data")); } }
        async public void LoadByPatchAsync()
        {
            try
            {
                StreamReader sw = new StreamReader(CurrentPatch,Encoding.UTF8);
                Data = await sw.ReadToEndAsync();
                sw.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
            FileLoaded?.Invoke(this,Data);
        }
        async public void SaveByPatchAsync()
        {
            try
            {
                StreamWriter sw = new StreamWriter(CurrentPatch,false,Encoding.UTF8);
                await sw.WriteAsync(Data);
                sw.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
            MessageBox.Show($"Saved\n{CurrentPatch}");
        }
    }
    
}
