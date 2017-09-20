#include "../Public/Link.h"


//begin namespace block
namespace CONTACTS
{

Link::Link()
{
	this->_ConstructorID = 1279839802;
}

Link::Link(PRIVATE::ContactLink* my_link, PRIVATE::ContactLink* foreign_link, COMMON::User* user)
{
	this->_ConstructorID = 1279839802;
	this->my_link = my_link;
	this->foreign_link = foreign_link;
	this->user = user;
}
void Link::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->my_link->OnSend(Writer);
	this->foreign_link->OnSend(Writer);
	this->user->OnSend(Writer);
}


void Link::OnResponce(BinaryReader& Reader)
{
	my_link = reinterpret_cast<PRIVATE::ContactLink*>(Reader.TGReadObject());
	foreign_link = reinterpret_cast<PRIVATE::ContactLink*>(Reader.TGReadObject());
	user = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
}
Link::~Link()
{

}
}//end namespace block
