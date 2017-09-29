#include "../Public/UpdateContactLink.h"


//begin namespace block
namespace COMMON
{

UpdateContactLink::UpdateContactLink()
{
	this->_ConstructorID = -1657903163;
}

UpdateContactLink::UpdateContactLink(int32 user_id, PRIVATE::ContactLink*  my_link, PRIVATE::ContactLink*  foreign_link)
{
	this->_ConstructorID = -1657903163;
	this->user_id = user_id;
	this->my_link = my_link;
	this->foreign_link = foreign_link;
}
void UpdateContactLink::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->user_id);
	this->my_link->OnSend(Writer);
	this->foreign_link->OnSend(Writer);
}


void UpdateContactLink::OnResponce(BinaryReader& Reader)
{
	user_id = Reader.ReadInt();
	my_link = reinterpret_cast<PRIVATE::ContactLink* >(Reader.TGReadObject());
	foreign_link = reinterpret_cast<PRIVATE::ContactLink* >(Reader.TGReadObject());
	this->_Responded = true;
}
UpdateContactLink::~UpdateContactLink()
{

}
}//end namespace block
