#include "../Public/Authorizations.h"


//begin namespace block
namespace ACCOUNT
{

Authorizations::Authorizations()
{
	this->_ConstructorID = -559198190;
}

Authorizations::Authorizations(TArray<COMMON::Authorization*> authorizations)
{
	this->_ConstructorID = -559198190;
	this->authorizations = authorizations;
}
void Authorizations::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->authorizations.Num());
	for(auto X : this->authorizations)
	{
	X->OnSend(Writer);
	}
}


void Authorizations::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len20170 = Reader.ReadInt();
	for(int32 i = 0; i < Len20170; i++)
	{
	auto X = reinterpret_cast<COMMON::Authorization*>(Reader.TGReadObject());
	authorizations.Add(X);
	}
}
Authorizations::~Authorizations()
{

}
}//end namespace block
