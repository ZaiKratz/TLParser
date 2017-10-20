#include "../Public/FoundGifs.h"


//begin namespace block
namespace MESSAGES
{

FoundGifs::FoundGifs()
{
	this->_ConstructorID = 1158290442;
}

FoundGifs::FoundGifs(int32 next_offset, TArray<COMMON::FoundGif*>  results)
{
	this->_ConstructorID = 1158290442;
	this->next_offset = next_offset;
	this->results = results;
}
void FoundGifs::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->next_offset);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->results.Num());
	for(auto X : this->results)
	{
	X->OnSend(Writer);
	}
}


void FoundGifs::OnResponce(BinaryReader& Reader)
{
	next_offset = Reader.ReadInt();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len20481 = Reader.ReadInt();
	for(int32 i = 0; i < Len20481; i++)
	{
	auto X = reinterpret_cast<COMMON::FoundGif*>(Reader.TGReadObject());
	results.Add(X);
	}
	this->_Responded = true;
}
FoundGifs::~FoundGifs()
{
}
}//end namespace block
