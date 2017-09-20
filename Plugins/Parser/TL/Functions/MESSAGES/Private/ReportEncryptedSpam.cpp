#include "../Public/ReportEncryptedSpam.h"


//begin namespace block
namespace MESSAGES
{

ReportEncryptedSpam::ReportEncryptedSpam()
{
	this->_ConstructorID = 260836427;
	this->_ContentRelated = true;
}

ReportEncryptedSpam::ReportEncryptedSpam(COMMON::InputEncryptedChat* peer)
{
	this->_ConstructorID = 260836427;
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
}
ReportEncryptedSpam::~ReportEncryptedSpam()
{

}
}//end namespace block
