#include "../Public/ReportEncryptedSpam.h"


//begin namespace block
namespace MESSAGES
{

ReportEncryptedSpam::ReportEncryptedSpam()
{
	this->_ConstructorID = 1259113487;
	this->_ContentRelated = true;
}

ReportEncryptedSpam::ReportEncryptedSpam(COMMON::InputEncryptedChat*  peer)
{
	this->_ConstructorID = 1259113487;
	this->_ContentRelated = true;
	this->peer = peer;
}
void ReportEncryptedSpam::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
}


void ReportEncryptedSpam::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
ReportEncryptedSpam::~ReportEncryptedSpam()
{
	if(this->peer)
	{
		delete this->peer;
	}
}
}//end namespace block
