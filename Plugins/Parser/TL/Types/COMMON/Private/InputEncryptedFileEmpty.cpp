#include "../Public/InputEncryptedFileEmpty.h"


//begin namespace block
namespace COMMON
{

InputEncryptedFileEmpty::InputEncryptedFileEmpty()
{
	this->_ConstructorID = 1690515224;
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
}
InputEncryptedFileEmpty::~InputEncryptedFileEmpty()
{

}
}//end namespace block
