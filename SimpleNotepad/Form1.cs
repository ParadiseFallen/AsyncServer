using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SimpleNotepad
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            TextBox.Text = Data.Data;
            this.Text = Data.CurrentPatch;
            this.Text = "Notepad";
            Data.PropertyChanged += (s, a) => {
                if (a.PropertyName == "CurrentPatch")
                    this.Text = $"Notepad : {Data.CurrentPatch}";
            };
            Data.FileLoaded += (s, a) => {
                TextBox.Text = Data.Data;
            };
            TextBox.TextChanged += (s, a) => { Data.Data = (s as RichTextBox).Text; Console.WriteLine(Data.Data); };
        }

        public NotepadData Data { get; set; } = new NotepadData();

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            using (var Form = new OpenFileDialog())
            {
                Form.Multiselect = false;
                var res = Form.ShowDialog();
                if (res == DialogResult.OK)
                {
                    Data.CurrentPatch = Form.FileName;
                    Data.LoadByPatchAsync();
                }
            }
            Console.WriteLine(TextBox.Text);
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (Data.CurrentPatch!="")
            {
                Data.SaveByPatchAsync();
            }
            else
            {

            }
        }
    }
}
