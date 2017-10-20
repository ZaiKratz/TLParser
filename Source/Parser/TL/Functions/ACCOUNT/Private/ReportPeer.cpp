#include "../Public/ReportPeer.h"


//begin namespace block
namespace ACCOUNT
{

ReportPeer::ReportPeer()
{
	this->_ConstructorID = -1374118561;
	this->_ContentRelated = true;
}

ReportPeer::ReportPeer(TLBaseObject*  peer, TLBaseObject*  reason)
{
	this->_ConstructorID = -1374118561;
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
	this->_Responded = true;
}
ReportPeer::~ReportPeer()
{
	if(this->peer)
	{
		delete this->peer;
	}
	if(this->reason)
	{
		delete this->reason;
	}
}
}//end namespace block
