#include "../Public/GetPinnedDialogs.h"


//begin namespace block
namespace MESSAGES
{

GetPinnedDialogs::GetPinnedDialogs()
{
	this->_ConstructorID = -497756594;
	this->_ContentRelated = true;
}
void GetPinnedDialogs::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetPinnedDialogs::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::PeerDialogs*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetPinnedDialogs::~GetPinnedDialogs()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
