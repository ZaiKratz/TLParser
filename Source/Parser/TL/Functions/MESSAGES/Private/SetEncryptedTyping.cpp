#include "../Public/SetEncryptedTyping.h"


//begin namespace block
namespace MESSAGES
{

SetEncryptedTyping::SetEncryptedTyping()
{
	this->_ConstructorID = 2031374829;
	this->_ContentRelated = true;
}

SetEncryptedTyping::SetEncryptedTyping(COMMON::InputEncryptedChat*  peer, bool typing)
{
	this->_ConstructorID = 2031374829;
	this->_ContentRelated = true;
	this->peer = peer;
	this->typing = typing;
}
void SetEncryptedTyping::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	Writer.WriteBool(this->typing);
}


void SetEncryptedTyping::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
SetEncryptedTyping::~SetEncryptedTyping()
{

}
}//end namespace block
