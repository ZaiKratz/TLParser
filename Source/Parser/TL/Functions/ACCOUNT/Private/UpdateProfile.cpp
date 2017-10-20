#include "../Public/UpdateProfile.h"


//begin namespace block
namespace ACCOUNT
{

UpdateProfile::UpdateProfile()
{
	this->_ConstructorID = 2018596725;
	this->_ContentRelated = true;
}

UpdateProfile::UpdateProfile(FString first_name, FString last_name, FString about)
{
	this->_ConstructorID = 2018596725;
	this->_ContentRelated = true;
	this->first_name = first_name;
	this->last_name = last_name;
	this->about = about;
}
void UpdateProfile::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!first_name.IsEmpty())
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!last_name.IsEmpty())
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!about.IsEmpty())
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.TGWriteString(this->first_name);
	Writer.TGWriteString(this->last_name);
	Writer.TGWriteString(this->about);
}


void UpdateProfile::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	this->_Responded = true;
}
UpdateProfile::~UpdateProfile()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
