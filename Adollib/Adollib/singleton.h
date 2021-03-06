#pragma once

namespace Adollib
{
	// ****************************************
	// Singleton (create-destroyで生成破棄, 参照返し)
	// ****************************************
	template <class T>
	class Singleton
	{
	private:
		static T* _instance;
	public:
		// 生成
		static void create()
		{
			if (_instance == nullptr)
			{
				_instance = new T;
			}
		}
		// 破棄
		static void destroy()
		{
			if (_instance != nullptr)
			{
				delete _instance;
				_instance = nullptr;
			}
		}
		// インスタンスの参照を取得
		static T& getInstance()
		{
			return *_instance;
		}
		// インスタンスのポインタを取得
		static T* getInstancePtr()
		{
			return _instance;
		}
		// インスタンスが存在するか
		static bool isCreate()
		{
			return _instance != nullptr;
		}
		// インスタンスが破棄されているか
		static bool isDestroy()
		{
			return _instance == nullptr;
		}
	protected:
		Singleton() = default;
		virtual ~Singleton() = default;

		Singleton(const Singleton&) = delete;
		Singleton& operator=(const Singleton&) = delete;
		Singleton(Singleton&&) = delete;
		Singleton& operator=(Singleton&&) = delete;

	};

	template<class T>
	T* Singleton<T>::_instance = nullptr;
}