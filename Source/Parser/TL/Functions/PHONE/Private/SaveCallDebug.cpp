#include "../Public/SaveCallDebug.h"


//begin namespace block
namespace PHONE
{

SaveCallDebug::SaveCallDebug()
{
	this->_ConstructorID = 662363518;
	this->_ContentRelated = true;
}

SaveCallDebug::SaveCallDebug(COMMON::InputPhoneCall*  peer, COMMON::DataJSON*  debug)
{
	this->_ConstructorID = 662363518;
	this->_ContentRelated = true;
	this->peer = peer;
	this->debug = debug;
}
void SaveCallDebug::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	this->debug->OnSend(Writer);
}


void SaveCallDebug::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
SaveCallDebug::~SaveCallDebug()
{
	if(this->peer)
	{
		delete this->peer;
	}
	if(this->debug)
	{
		delete this->debug;
	}
}
}//end namespace block
