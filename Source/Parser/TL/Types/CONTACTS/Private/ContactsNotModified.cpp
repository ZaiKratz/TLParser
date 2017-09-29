#include "../Public/ContactsNotModified.h"


//begin namespace block
namespace CONTACTS
{

ContactsNotModified::ContactsNotModified()
{
	this->_ConstructorID = -1219778094;
}
void ContactsNotModified::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void ContactsNotModified::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
ContactsNotModified::~ContactsNotModified()
{

}
}//end namespace block
