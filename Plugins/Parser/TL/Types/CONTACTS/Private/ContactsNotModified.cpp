#include "../Public/ContactsNotModified.h"


//begin namespace block
namespace CONTACTS
{

ContactsNotModified::ContactsNotModified()
{
	this->_ConstructorID = -760656969;
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
}
ContactsNotModified::~ContactsNotModified()
{

}
}//end namespace block
