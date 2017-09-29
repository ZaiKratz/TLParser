#include "../Public/InputEncryptedFileEmpty.h"


//begin namespace block
namespace COMMON
{

InputEncryptedFileEmpty::InputEncryptedFileEmpty()
{
	this->_ConstructorID = 406307684;
}
void InputEncryptedFileEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputEncryptedFileEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputEncryptedFileEmpty::~InputEncryptedFileEmpty()
{

}
}//end namespace block
