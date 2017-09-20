#include "../Public/UpdateDcOptions.h"


//begin namespace block
namespace COMMON
{

UpdateDcOptions::UpdateDcOptions()
{
	this->_ConstructorID = 1939365518;
}

UpdateDcOptions::UpdateDcOptions(TArray<COMMON::DcOption*> dc_options)
{
	this->_ConstructorID = 1939365518;
	this->dc_options = dc_options;
}
void UpdateDcOptions::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->dc_options.Num());
	for(auto X : this->dc_options)
	{
	X->OnSend(Writer);
	}
}


void UpdateDcOptions::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len26244 = Reader.ReadInt();
	for(int32 i = 0; i < Len26244; i++)
	{
	auto X = reinterpret_cast<COMMON::DcOption*>(Reader.TGReadObject());
	dc_options.Add(X);
	}
}
UpdateDcOptions::~UpdateDcOptions()
{

}
}//end namespace block
