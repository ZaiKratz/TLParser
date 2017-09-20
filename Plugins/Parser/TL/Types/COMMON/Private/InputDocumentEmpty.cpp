#include "../Public/InputDocumentEmpty.h"


//begin namespace block
namespace COMMON
{

InputDocumentEmpty::InputDocumentEmpty()
{
	this->_ConstructorID = -1360334734;
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
}
InputDocumentEmpty::~InputDocumentEmpty()
{

}
}//end namespace block
