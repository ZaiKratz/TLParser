#include "../Public/EncryptedFileEmpty.h"


//begin namespace block
namespace COMMON
{

EncryptedFileEmpty::EncryptedFileEmpty()
{
	this->_ConstructorID = -1038136962;
}
void EncryptedFileEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void EncryptedFileEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
EncryptedFileEmpty::~EncryptedFileEmpty()
{

}
}//end namespace block