#include "../Public/DiscardEncryption.h"


//begin namespace block
namespace MESSAGES
{

DiscardEncryption::DiscardEncryption()
{
	this->_ConstructorID = -304536635;
	this->_ContentRelated = true;
}

DiscardEncryption::DiscardEncryption(int32 chat_id)
{
	this->_ConstructorID = -304536635;
	this->_ContentRelated = true;
	this->chat_id = chat_id;
}
void DiscardEncryption::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->chat_id);
}


void DiscardEncryption::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
DiscardEncryption::~DiscardEncryption()
{
}
}//end namespace block
