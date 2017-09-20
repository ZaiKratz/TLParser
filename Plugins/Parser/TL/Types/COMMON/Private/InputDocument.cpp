#include "../Public/InputDocument.h"


//begin namespace block
namespace COMMON
{

InputDocument::InputDocument()
{
	this->_ConstructorID = 1384741144;
}

InputDocument::InputDocument(unsigned long long id, unsigned long long access_hash)
{
	this->_ConstructorID = 1384741144;
	this->id = id;
	this->access_hash = access_hash;
}
void InputDocument::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->id);
	Writer.WriteLong(this->access_hash);
}


void InputDocument::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadLong();
	access_hash = Reader.ReadLong();
}
InputDocument::~InputDocument()
{

}
}//end namespace block
