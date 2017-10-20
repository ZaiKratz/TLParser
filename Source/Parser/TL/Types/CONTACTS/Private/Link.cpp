#include "../Public/Link.h"


//begin namespace block
namespace CONTACTS
{

Link::Link()
{
	this->_ConstructorID = 986597452;
}

Link::Link(TLBaseObject*  my_link, TLBaseObject*  foreign_link, COMMON::User*  user)
{
	this->_ConstructorID = 986597452;
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
	my_link = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	foreign_link = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	user = reinterpret_cast<COMMON::User* >(Reader.TGReadObject());
	this->_Responded = true;
}
Link::~Link()
{
	if(this->my_link)
	{
		delete this->my_link;
	}
	if(this->foreign_link)
	{
		delete this->foreign_link;
	}
	if(this->user)
	{
		delete this->user;
	}
}
}//end namespace block
