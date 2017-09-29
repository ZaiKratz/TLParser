#include "../Public/UpdateContactsReset.h"


//begin namespace block
namespace COMMON
{

UpdateContactsReset::UpdateContactsReset()
{
	this->_ConstructorID = 1887741886;
}
void UpdateContactsReset::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void UpdateContactsReset::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
UpdateContactsReset::~UpdateContactsReset()
{

}
}//end namespace block
