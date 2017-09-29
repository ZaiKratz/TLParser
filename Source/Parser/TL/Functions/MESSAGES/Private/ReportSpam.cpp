#include "../Public/ReportSpam.h"


//begin namespace block
namespace MESSAGES
{

ReportSpam::ReportSpam()
{
	this->_ConstructorID = -820669733;
	this->_ContentRelated = true;
}

ReportSpam::ReportSpam(PRIVATE::InputPeer*  peer)
{
	this->_ConstructorID = -820669733;
	this->_ContentRelated = true;
	this->peer = peer;
}
void ReportSpam::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
}


void ReportSpam::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
ReportSpam::~ReportSpam()
{

}
}//end namespace block
