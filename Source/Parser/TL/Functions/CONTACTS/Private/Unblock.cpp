#include "../Public/Unblock.h"


//begin namespace block
namespace CONTACTS
{

Unblock::Unblock()
{
	this->_ConstructorID = -448724803;
	this->_ContentRelated = true;
}

Unblock::Unblock(COMMON::InputUser*  id)
{
	this->_ConstructorID = -448724803;
	this->_ContentRelated = true;
	this->id = id;
}
void Unblock::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->id->OnSend(Writer);
}


void Unblock::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
Unblock::~Unblock()
{

}
}//end namespace block
