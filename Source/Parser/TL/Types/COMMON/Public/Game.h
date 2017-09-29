#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Photo.h"
#include "../../../Types/Common/Public/Document.h"

//begin namespace block
namespace COMMON
{
class Game : public TLBaseObject
{
public:
	Game();
	Game(unsigned long long id, unsigned long long access_hash, FString short_name, FString title, FString description, COMMON::Photo* photo, COMMON::Document* document);

	~Game();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long Getid() const
	{
		 return this->id;
	}

	unsigned long long GetAccessHash() const
	{
		 return this->access_hash;
	}

	FString GetShortName() const
	{
		 return this->short_name;
	}

	FString Gettitle() const
	{
		 return this->title;
	}

	FString Getdescription() const
	{
		 return this->description;
	}

	COMMON::Photo*  Getphoto() const
	{
		 return this->photo;
	}

	COMMON::Document*  Getdocument() const
	{
		 return this->document;
	}

private:
	unsigned long long id;
	 unsigned long long access_hash;
	 FString short_name;
	 FString title;
	 FString description;
	 COMMON::Photo* photo;
	 COMMON::Document* document;
};
} //end namespace block
