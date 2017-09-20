#include "../Public/UpdateContactsReset.h"


//begin namespace block
namespace COMMON
{

UpdateContactsReset::UpdateContactsReset()
{
	this->_ConstructorID = -1096317840;
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
}
UpdateContactsReset::~UpdateContactsReset()
{

}
}//end namespace block
