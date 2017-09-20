#include "../Public/InputWebDocument.h"


//begin namespace block
namespace COMMON
{

InputWebDocument::InputWebDocument()
{
	this->_ConstructorID = 1296297371;
}

InputWebDocument::InputWebDocument(FString url, int32 size, FString mime_type, TArray<PRIVATE::DocumentAttribute*> attributes)
{
	this->_ConstructorID = 1296297371;
	this->url = url;
	this->size = size;
	this->mime_type = mime_type;
	this->attributes = attributes;
}
void InputWebDocument::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->url);
	Writer.WriteInt(this->size);
	Writer.TGWriteString(this->mime_type);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->attributes.Num());
	for(auto X : this->attributes)
	{
	X->OnSend(Writer);
	}
}


void InputWebDocument::OnResponce(BinaryReader& Reader)
{
	url = Reader.TGReadString();
	size = Reader.ReadInt();
	mime_type = Reader.TGReadString();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len8884 = Reader.ReadInt();
	for(int32 i = 0; i < Len8884; i++)
	{
	auto X = reinterpret_cast<PRIVATE::DocumentAttribute*>(Reader.TGReadObject());
	attributes.Add(X);
	}
}
InputWebDocument::~InputWebDocument()
{

}
}//end namespace block
