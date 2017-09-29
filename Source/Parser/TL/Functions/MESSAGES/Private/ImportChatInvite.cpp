#include "../Public/ImportChatInvite.h"


//begin namespace block
namespace MESSAGES
{

ImportChatInvite::ImportChatInvite()
{
	this->_ConstructorID = 1817183516;
	this->_ContentRelated = true;
}

ImportChatInvite::ImportChatInvite(FString hash)
{
	this->_ConstructorID = 1817183516;
	this->_ContentRelated = true;
	this->hash = hash;
}
void ImportChatInvite::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->hash);
}


void ImportChatInvite::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
	this->_Responded = true;
}
ImportChatInvite::~ImportChatInvite()
{

}
}//end namespace block
