#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace HELP
{
class TermsOfService : public TLBaseObject
{
public:
	TermsOfService();
	TermsOfService(FString text);

	~TermsOfService();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Gettext() const
	{
		 return this->text;
	}

private:
	FString text;
};
} //end namespace block
