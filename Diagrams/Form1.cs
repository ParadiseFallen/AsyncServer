using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Diagrams
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            FormulsList.Items.Add("y = sin(x)");
            FormulsList.Items.Add("y = x^2");
            FormulsList.Items.Add("y = 1/x");
            this.Paint += (object sender, PaintEventArgs e) =>
                Draw(e.Graphics);

            numericUpDownMinVal.Value = 1;
            numericUpDownMinVal.Minimum = 1;
            numericUpDownMaxVal.Minimum = 2;
            numericUpDownMaxVal.Value = 2;
            dXNumeric.Minimum = -100000;
            dXNumeric.Maximum = 100000;
            Scale.Minimum = 1;
        }
        public bool DrawG { get; set; } = false;
        private double GetPoint(double pos)
        {
            switch (FormulsList.SelectedItem)
            {
                case "y = sin(x)":
                    return Math.Sin(pos);
                case "y = x^2":
                    return Math.Pow(pos,2);
                case "y = 1/x":
                    return 1/pos;
            }
            return 0;
        }

        private void Draw(Graphics g)
        {
            if (!DrawG)
                return;
            for (double i = Decimal.ToDouble(numericUpDownMinVal.Value); i < Decimal.ToInt32(numericUpDownMaxVal.Value); i+= 1f/Width)
            {
                g.ResetTransform();
                g.TranslateTransform(this.Width / 2,this.Height / 2 );
                g.TranslateTransform((float)i * (float)Scale.Value+ (float)dXNumeric.Value, (float)GetPoint(i) * (float)Scale.Value);
                g.DrawRectangle(new Pen(Color.Red), 0, 0, 1, 1);
                g.ScaleTransform(4, 4);
                Console.WriteLine($"{(float)GetPoint(i)}:{ (float)i}");
                //g.TranslateTransform(this.Height);
            }
            DrawG = false;
        }
        private void formulaToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void toolStripComboBox1_Click(object sender, EventArgs e)
        {

        }

        private void colorToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void toolStripComboBox2_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void numericUpDownMaxVal_ValueChanged(object sender, EventArgs e)
        {

        }

        private void numericUpDownMinVal_ValueChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.DrawG = true;
            this.Invalidate();
        }
    }
}
