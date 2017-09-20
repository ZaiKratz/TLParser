#include "../Public/ImportChatInvite.h"


//begin namespace block
namespace MESSAGES
{

ImportChatInvite::ImportChatInvite()
{
	this->_ConstructorID = 470110316;
	this->_ContentRelated = true;
}

ImportChatInvite::ImportChatInvite(FString hash)
{
	this->_ConstructorID = 470110316;
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
}
ImportChatInvite::~ImportChatInvite()
{

}
}//end namespace block
