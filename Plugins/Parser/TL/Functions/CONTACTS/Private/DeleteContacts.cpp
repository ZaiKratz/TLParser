#include "../Public/DeleteContacts.h"


//begin namespace block
namespace CONTACTS
{

DeleteContacts::DeleteContacts()
{
	this->_ConstructorID = -1640453287;
	this->_ContentRelated = true;
}

DeleteContacts::DeleteContacts(TArray<COMMON::InputUser*> id)
{
	this->_ConstructorID = -1640453287;
	this->_ContentRelated = true;
	this->id = id;
}
void DeleteContacts::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->id.Num());
	for(auto X : this->id)
	{
	X->OnSend(Writer);
	}
}


void DeleteContacts::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
}
DeleteContacts::~DeleteContacts()
{

}
}//end namespace block
