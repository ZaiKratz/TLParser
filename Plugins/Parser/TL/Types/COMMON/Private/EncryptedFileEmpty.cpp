#include "../Public/EncryptedFileEmpty.h"


//begin namespace block
namespace COMMON
{

EncryptedFileEmpty::EncryptedFileEmpty()
{
	this->_ConstructorID = 2118721474;
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
}
EncryptedFileEmpty::~EncryptedFileEmpty()
{

}
}//end namespace block
