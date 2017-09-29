#include "../Public/HideReportSpam.h"


//begin namespace block
namespace MESSAGES
{

HideReportSpam::HideReportSpam()
{
	this->_ConstructorID = -1460572005;
	this->_ContentRelated = true;
}

HideReportSpam::HideReportSpam(PRIVATE::InputPeer*  peer)
{
	this->_ConstructorID = -1460572005;
	this->_ContentRelated = true;
	this->peer = peer;
}
void HideReportSpam::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
}


void HideReportSpam::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
HideReportSpam::~HideReportSpam()
{

}
}//end namespace block
