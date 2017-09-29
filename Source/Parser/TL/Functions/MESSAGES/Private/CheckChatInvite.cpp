#include "../Public/CheckChatInvite.h"


//begin namespace block
namespace MESSAGES
{

CheckChatInvite::CheckChatInvite()
{
	this->_ConstructorID = 1051570619;
	this->_ContentRelated = true;
}

CheckChatInvite::CheckChatInvite(FString hash)
{
	this->_ConstructorID = 1051570619;
	this->_ContentRelated = true;
	this->hash = hash;
}
void CheckChatInvite::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->hash);
}


void CheckChatInvite::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::ChatInvite*>(Reader.TGReadObject());
	this->_Responded = true;
}
CheckChatInvite::~CheckChatInvite()
{

}
}//end namespace block
