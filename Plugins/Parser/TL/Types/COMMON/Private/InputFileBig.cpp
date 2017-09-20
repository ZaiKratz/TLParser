#include "../Public/InputFileBig.h"


//begin namespace block
namespace COMMON
{

InputFileBig::InputFileBig()
{
	this->_ConstructorID = -1257549830;
}

InputFileBig::InputFileBig(unsigned long long id, int32 parts, FString name)
{
	this->_ConstructorID = -1257549830;
	this->id = id;
	this->parts = parts;
	this->name = name;
}
void InputFileBig::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->id);
	Writer.WriteInt(this->parts);
	Writer.TGWriteString(this->name);
}


void InputFileBig::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadLong();
	parts = Reader.ReadInt();
	name = Reader.TGReadString();
}
InputFileBig::~InputFileBig()
{

}
}//end namespace block
