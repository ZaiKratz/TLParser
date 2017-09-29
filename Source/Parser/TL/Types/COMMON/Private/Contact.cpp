#include "../Public/Contact.h"


//begin namespace block
namespace COMMON
{

Contact::Contact()
{
	this->_ConstructorID = -116274796;
}

Contact::Contact(int32 user_id, bool mutual)
{
	this->_ConstructorID = -116274796;
	this->user_id = user_id;
	this->mutual = mutual;
}
void Contact::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->user_id);
	Writer.WriteBool(this->mutual);
}


void Contact::OnResponce(BinaryReader& Reader)
{
	user_id = Reader.ReadInt();
	mutual = Reader.ReadBool();
	this->_Responded = true;
}
Contact::~Contact()
{

}
}//end namespace block
