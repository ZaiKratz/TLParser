#include "../Public/PasswordInputSettings.h"


//begin namespace block
namespace ACCOUNT
{

PasswordInputSettings::PasswordInputSettings()
{
	this->_ConstructorID = -2037289493;
}

PasswordInputSettings::PasswordInputSettings(TArray<uint8>  new_salt, TArray<uint8>  new_password_hash, FString hint, FString email)
{
	this->_ConstructorID = -2037289493;
	this->new_salt = new_salt;
	this->new_password_hash = new_password_hash;
	this->hint = hint;
	this->email = email;
}
void PasswordInputSettings::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(new_salt.Num())
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(new_password_hash.Num())
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!hint.IsEmpty())
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!email.IsEmpty())
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	if(this->new_salt.Num())
	{
	Writer.TGWriteBytes((unsigned char*)this->new_salt.GetData(), this->new_salt.Num());
	}
	if(this->new_password_hash.Num())
	{
	Writer.TGWriteBytes((unsigned char*)this->new_password_hash.GetData(), this->new_password_hash.Num());
	}
	Writer.TGWriteString(this->hint);
	Writer.TGWriteString(this->email);
}


void PasswordInputSettings::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
	new_salt = Reader.TGReadBytes();
	}
	if((Flags & (1 << 0)) != 0) 
	{
	new_password_hash = Reader.TGReadBytes();
	}
	if((Flags & (1 << 0)) != 0) 
	{
	hint = Reader.TGReadString();
	}
	if((Flags & (1 << 1)) != 0) 
	{
	email = Reader.TGReadString();
	}
	this->_Responded = true;
}
PasswordInputSettings::~PasswordInputSettings()
{

}
}//end namespace block
