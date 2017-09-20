#include "../Public/ReportPeer.h"


//begin namespace block
namespace ACCOUNT
{

ReportPeer::ReportPeer()
{
	this->_ConstructorID = 1604130990;
	this->_ContentRelated = true;
}

ReportPeer::ReportPeer(PRIVATE::InputPeer* peer, PRIVATE::ReportReason* reason)
{
	this->_ConstructorID = 1604130990;
	this->_ContentRelated = true;
	this->peer = peer;
	this->reason = reason;
}
void ReportPeer::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	this->reason->OnSend(Writer);
}


void ReportPeer::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
}
ReportPeer::~ReportPeer()
{

}
}//end namespace block