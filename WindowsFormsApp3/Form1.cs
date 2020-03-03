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

namespace WindowsFormsApp3
{
    public partial class Form1 : Form
    {
        private string CurrentPatch = "";
        public Form1()
        {
            InitializeComponent();
            LoadDiscInfo();
            listView1.TileSize = new Size(100,100);
        }
        private void LoadDiscInfo()
        {
            DriveInfo[] drives = DriveInfo.GetDrives();
            foreach (DriveInfo drive in drives)
            {
                listView1.Items.Add(drive.Name);
            }
        }
        private void LoadDirectoryInfo(string Path)
        {
            listView1.Items.Clear();
            if (Path == "")
            {
                LoadDiscInfo();
                return;
            }
            var DI = new DirectoryInfo(Path);
            listView1.Items.Add("Back");
            try
            {
                foreach (var item in DI.GetFiles())
                {
                    listView1.Items.Add(item.Name);
                }
            }
            catch (Exception)
            {}
            try
            {
                foreach (var item in DI.GetDirectories())
                {
                    listView1.Items.Add(item.Name);
                }
            }
            catch (Exception)
            {}
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {
           
        }
        
        private void OpenFile(string path)
        {
            try
            {
                File.Open(path, FileMode.Open);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
        }

        private bool IsDirectory(string v)
        {
            return !File.Exists(v);
        }

        private void listView1_ItemActivate(object sender, EventArgs e)
        {
          if ((sender as ListView).SelectedItems.Count == 1)
            {
                if (IsDirectory(CurrentPatch + (sender as ListView).SelectedItems[0].Text))
                {
                    if ((sender as ListView).SelectedItems[0].Text == "Back")
                    {
                        try
                        {
                            CurrentPatch = new DirectoryInfo(CurrentPatch).Parent.FullName;
                        }
                        catch (Exception)
                        {
                            CurrentPatch = "";
                        }
                    }
                    else
                    {
                        if (!(sender as ListView).SelectedItems[0].Text.Contains("\\"))
                        CurrentPatch += $"\\{(sender as ListView).SelectedItems[0].Text}";
                        else
                        CurrentPatch += (sender as ListView).SelectedItems[0].Text;

                    }
                    Console.WriteLine((sender as ListView).SelectedItems[0].Text);
                    LoadDirectoryInfo(CurrentPatch);
                }
                else
                {
                    OpenFile(CurrentPatch + (sender as ListView).SelectedItems[0].Text);
                }
                this.Text = CurrentPatch;
            }
        }
    }
}
