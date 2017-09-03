using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.ServiceModel;
using Client.ChatService;

namespace Client
{
	public partial class frmClient : Form
	{
		ReceiveClient rc = null;
		string myName;

		public frmClient()
		{
			InitializeComponent();
			this.FormClosing += new FormClosingEventHandler(frmClient_FormClosing);
			this.txtSend.KeyPress += new KeyPressEventHandler(txtSend_KeyPress);
		}

		void txtSend_KeyPress(object sender, KeyPressEventArgs e)
		{
			int keyValue = (int)e.KeyChar;
			if (keyValue == 13)
				SendMessage();
		}

		private void frmClient_FormClosing(object sender, EventArgs e)
		{
			rc.Stop(myName);
		}

		private void frmClient_Load(object sender, EventArgs e)
		{
			txtMsgs.Enabled = false;
			txtSend.Enabled = false;
			btnSend.Enabled = false;
		}

		void rc_ReceiveMsg(string sender, string msg)
		{
			if (msg.Length > 0)
				txtMsgs.Text += Environment.NewLine + sender + ":     " + msg;
		}

		void rc_NewNames(object sender, List<string> names)
		{
			lstClients.Items.Clear();
			foreach (string name in names)
			{
				if (name != myName)
					lstClients.Items.Add(name);
			}
		}

		private void btnSend_Click(object sender, EventArgs e)
		{
			if (txtSend.TextLength != 0)
				SendMessage();
		}

		private void SendMessage()
		{
			if (!checkBox_Broadcast.Checked)
			{
				if (lstClients.Items.Count == 0) return;
				if (lstClients.SelectedItems.Count == 0)
				{
					txtMsgs.Text += Environment.NewLine + myName + " > " + lstClients.Items[0].ToString() + ":     " + txtSend.Text;
					rc.SendMessage(txtSend.Text, myName, lstClients.Items[0].ToString());
				}
				else
					if (!string.IsNullOrEmpty(lstClients.SelectedItem.ToString()))
				{
					txtMsgs.Text += Environment.NewLine + myName + " > " + lstClients.SelectedItem.ToString() + ":     " + txtSend.Text;
					rc.SendMessage(txtSend.Text, myName, lstClients.SelectedItem.ToString());
				}
				txtSend.Clear();
			}
			else
			{
				txtMsgs.Text += Environment.NewLine + myName + " > ALL:     " + txtSend.Text;
				foreach (var items in lstClients.Items)
				{
					rc.SendMessage(txtSend.Text, myName, items.ToString());
				}
			}
		}

		private void btnLogin_Click(object sender, EventArgs e)
		{
			if (txtUserName.Text.Length > 0)
			{
				txtMsgs.Enabled = true;
				txtSend.Enabled = true;
				btnSend.Enabled = true;
				txtMsgs.ReadOnly = true;
				txtUserName.ReadOnly = true;
				txtUserName.BackColor = Color.White;
				txtMsgs.BackColor = Color.White;

				myName = txtUserName.Text.Trim();
				rc = new ReceiveClient();
				rc.Start(rc, myName);

				rc.NewNames += new GotNames(rc_NewNames);
				rc.ReceiveMsg += new ReceviedMessage(rc_ReceiveMsg);
			}
			else
			{
				txtMsgs.Enabled = false;
				txtSend.Enabled = false;
				btnSend.Enabled = false;
			}
		}
	}

}
