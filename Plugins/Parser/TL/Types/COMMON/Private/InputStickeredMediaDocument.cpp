#include "../Public/InputStickeredMediaDocument.h"


//begin namespace block
namespace COMMON
{

InputStickeredMediaDocument::InputStickeredMediaDocument()
{
	this->_ConstructorID = 64;
}

InputStickeredMediaDocument::InputStickeredMediaDocument(COMMON::InputDocument* id)
{
	this->_ConstructorID = 64;
	this->id = id;
}
void InputStickeredMediaDocument::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->id->OnSend(Writer);
}


void InputStickeredMediaDocument::OnResponce(BinaryReader& Reader)
{
	id = reinterpret_cast<COMMON::InputDocument*>(Reader.TGReadObject());
}
InputStickeredMediaDocument::~InputStickeredMediaDocument()
{

}
}//end namespace block
