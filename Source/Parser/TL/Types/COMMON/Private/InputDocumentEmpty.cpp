#include "../Public/InputDocumentEmpty.h"


//begin namespace block
namespace COMMON
{

InputDocumentEmpty::InputDocumentEmpty()
{
	this->_ConstructorID = 1928391342;
}
void InputDocumentEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputDocumentEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputDocumentEmpty::~InputDocumentEmpty()
{

}
}//end namespace block
