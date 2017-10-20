#include "../Public/LangPackStringPluralized.h"


//begin namespace block
namespace COMMON
{

LangPackStringPluralized::LangPackStringPluralized()
{
	this->_ConstructorID = 1816636575;
}

LangPackStringPluralized::LangPackStringPluralized(FString key, FString zero_value, FString one_value, FString two_value, FString few_value, FString many_value, FString other_value)
{
	this->_ConstructorID = 1816636575;
	this->key = key;
	this->zero_value = zero_value;
	this->one_value = one_value;
	this->two_value = two_value;
	this->few_value = few_value;
	this->many_value = many_value;
	this->other_value = other_value;
}
void LangPackStringPluralized::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!zero_value.IsEmpty())
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!one_value.IsEmpty())
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!two_value.IsEmpty())
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(!few_value.IsEmpty())
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	if(!many_value.IsEmpty())
	{
		Flags |= (1 << 4);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.TGWriteString(this->key);
	Writer.TGWriteString(this->zero_value);
	Writer.TGWriteString(this->one_value);
	Writer.TGWriteString(this->two_value);
	Writer.TGWriteString(this->few_value);
	Writer.TGWriteString(this->many_value);
	Writer.TGWriteString(this->other_value);
}


void LangPackStringPluralized::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	key = Reader.TGReadString();
	if((Flags & (1 << 0)) != 0) 
	{
	zero_value = Reader.TGReadString();
	}
	if((Flags & (1 << 1)) != 0) 
	{
	one_value = Reader.TGReadString();
	}
	if((Flags & (1 << 2)) != 0) 
	{
	two_value = Reader.TGReadString();
	}
	if((Flags & (1 << 3)) != 0) 
	{
	few_value = Reader.TGReadString();
	}
	if((Flags & (1 << 4)) != 0) 
	{
	many_value = Reader.TGReadString();
	}
	other_value = Reader.TGReadString();
	this->_Responded = true;
}
LangPackStringPluralized::~LangPackStringPluralized()
{
}
}//end namespace block
