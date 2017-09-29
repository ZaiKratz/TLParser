#include "../Public/InputPaymentCredentials.h"


//begin namespace block
namespace COMMON
{

InputPaymentCredentials::InputPaymentCredentials()
{
	this->_ConstructorID = 873977640;
}

InputPaymentCredentials::InputPaymentCredentials(bool save, COMMON::DataJSON*  data)
{
	this->_ConstructorID = 873977640;
	this->save = save;
	this->data = data;
}
void InputPaymentCredentials::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(save)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->data->OnSend(Writer);
}


void InputPaymentCredentials::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		save = true;
	}
	data = reinterpret_cast<COMMON::DataJSON* >(Reader.TGReadObject());
	this->_Responded = true;
}
InputPaymentCredentials::~InputPaymentCredentials()
{

}
}//end namespace block
