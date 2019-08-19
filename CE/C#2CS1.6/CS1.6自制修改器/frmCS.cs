using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CS1._6自制修改器
{
    public partial class frmCS : Form
    {
        public frmCS()
        {
            InitializeComponent();
        }
        string name = "cstrike";
        int baseadress = 0x025069BC;
        private void timMoney_Tick(object sender, EventArgs e)
        {
            timMoney .Interval = 500;
            int adress1 = ECHelper.ReadMemoryValue(name, (IntPtr)baseadress);
            adress1 = adress1 + 0x7C;
            int adress2 = ECHelper.ReadMemoryValue(name, (IntPtr)adress1);
            adress2 = adress2 + 0x1CC;
            ECHelper.WriteMemoryValue(name, (IntPtr)adress2, 0x1869F);          //cs钱无线
        }

        private void btnMoney_Click(object sender, EventArgs e)
        {
            timMoney.Start();
        }

        private void timBlood_Tick(object sender, EventArgs e)
        {
            timBlood.Interval=100;
            int adress1 = ECHelper.ReadMemoryValue(name, (IntPtr)baseadress);
            adress1 = adress1 + 0x1E0;
            ECHelper.WriteMemoryValue(name, (IntPtr)adress1, 1139999456);          //cs血无限1139999456
        }

        private void btnShoot_Click(object sender, EventArgs e)
        {
            timShoot.Start();
        }

        private void timShoot_Tick(object sender, EventArgs e)
        {
            timShoot.Interval = 300;
            int adress1 = ECHelper.ReadMemoryValue(name, (IntPtr)baseadress);
            adress1 = adress1 + 0x7C;
            int adress2 = ECHelper.ReadMemoryValue(name, (IntPtr)adress1);
            adress2 = adress2 + 0x5EC;
            int adress3 = ECHelper.ReadMemoryValue(name, (IntPtr)adress2);
            adress3 = adress3 + 0xCC;
            ECHelper.WriteMemoryValue(name, (IntPtr)adress3, 0x64);          //cs子弹无线
        }

        private void timBoom_Tick(object sender, EventArgs e)
        {
            
        }

        private void btnBoom_Click(object sender, EventArgs e)
        {
            int adress1 = ECHelper.ReadMemoryValue(name, (IntPtr)baseadress);
            adress1 = adress1 + 0x7C;
            int adress2 = ECHelper.ReadMemoryValue(name, (IntPtr)adress1);
            adress2 = adress2 + 0x628;
            ECHelper.WriteMemoryValue(name, (IntPtr)adress2, 0x3E7);          //cs高爆手雷无限
        }

        private void btnBlood_Click(object sender, EventArgs e)
        {
            timBlood.Start();
        }

        private void timDefence_Tick(object sender, EventArgs e)
        {
            timDefence.Interval = 200;
            int adress1 = ECHelper.ReadMemoryValue(name, (IntPtr)baseadress);
            adress1 = adress1 + 0x7c;
            int adress2 = ECHelper.ReadMemoryValue(name, (IntPtr)adress1);
            adress2 = adress2 + 0x4;
            int adress3 = ECHelper.ReadMemoryValue(name, (IntPtr)adress2);
            adress3 = adress3 + 0x1bc;
            ECHelper.WriteMemoryValue(name, (IntPtr)adress3, 1139999456);          //cs护甲无限1139999456
        }

        private void btnDefence_Click(object sender, EventArgs e)
        {
            timDefence.Start();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            ToolTip tt = new ToolTip();
            tt.InitialDelay = 100;
            tt.AutoPopDelay = 4000;
            tt.SetToolTip(btnBlood ,"血量不减，注意火力的伤害，秒杀会死亡");
            tt.SetToolTip(btnBoom  , "必须先购买高爆手雷然后点击此功能，否则本局无法使用高爆");
            tt.SetToolTip(btnDefence  , "和血量同理,高于血量和护甲的伤害会死亡");
            tt.SetToolTip(btnMoney, "金钱会在每次买东西前变为最大值，显示金钱数=最大金钱数-花费价格");
            tt.SetToolTip(btnShoot, "子弹不减");
        }
        private void btnGame_Click(object sender, EventArgs e)
        {
           if (ECHelper.GetPIDByProcessName(name)==0)
	       {
               MessageBox.Show("在这之前总要启动游戏吧~~~~");
	       }
           else
           {
               btnBlood.Enabled = true;
               btnBoom.Enabled = true;
               btnDefence.Enabled = true;
               btnMoney.Enabled = true;
               btnShoot.Enabled = true;
               btnGame.Text = "已启动";
           }
        }
    }
}
