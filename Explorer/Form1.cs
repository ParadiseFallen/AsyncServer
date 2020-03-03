using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.ListView;

namespace Explorer
{
    public partial class Form1 : Form
    {
        private ListViewItemCollection DirectoryData;
        public string CurrentDirectory { get; set; } = "";
        public Form1()
        {
            InitializeComponent();
            DirectoryData = ListViewDirectory.Items;
            /*
             ListViewDirectory
             */
            LoadDirectoryInfo(CurrentDirectory);
            ListViewDirectory.ItemActivate += (s, a) => {
                if ((s as ListView).SelectedItems.Count == 1)
                {
                    Open($"{CurrentDirectory}/{(s as ListView).SelectedItems[0].Text}");
                }

                };
        }

        private void TreeViewDirectory_AfterSelect(object sender, TreeViewEventArgs e)
        {
            /*Open new*/
        }

        /*File or directory*/
        private void Open(string Path)
        {
            if (Path.Contains("."))
            {
                /*File*/
                new FileInfo(Path).Open(FileMode.Open);
            }
            else
            {
                DirectoryData.Clear();
                LoadDirectoryInfo(Path);
                /*Directory*/
            }
        }
        private void LoadDirectoryInfo(string path)
        {
            if (path == "")
            {
                foreach (var item in DriveInfo.GetDrives())
                {
                    DirectoryData.Add(item.Name);
                }
            }
            else
            {
                var d = new DirectoryInfo(path);
                /*load directories*/
                foreach (var item in d.GetDirectories())
                    DirectoryData.Add(item.Name);
                /*Load filenames*/
                foreach (var item in d.GetFiles())
                    DirectoryData.Add(item.Name);
            }
        }
    }
}
