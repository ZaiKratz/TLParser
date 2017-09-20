#include "../Public/CheckChatInvite.h"


//begin namespace block
namespace MESSAGES
{

CheckChatInvite::CheckChatInvite()
{
	this->_ConstructorID = -1145983682;
	this->_ContentRelated = true;
}

CheckChatInvite::CheckChatInvite(FString hash)
{
	this->_ConstructorID = -1145983682;
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
}
CheckChatInvite::~CheckChatInvite()
{

}
}//end namespace block
