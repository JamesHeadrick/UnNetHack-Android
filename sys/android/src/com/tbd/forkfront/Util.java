package com.tbd.forkfront;

import android.app.Activity;
import android.content.Context;
import android.content.res.Configuration;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.inputmethod.InputMethodManager;
import android.widget.EditText;

import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;
import androidx.core.view.WindowInsetsControllerCompat;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class Util
{
	// ____________________________________________________________________________________
	static public View inflate(Context context, int layoutId)
	{
		LayoutInflater vi = (LayoutInflater)context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
		return vi.inflate(layoutId, null);
	}
	
	// ____________________________________________________________________________________
	static public View inflate(Context context, int layoutId, View parent)
	{
		View v = inflate(context, layoutId);
		((ViewGroup)parent).addView(v);
		return v;
	}
	
	// ____________________________________________________________________________________
	static public View inflate(Activity context, int layoutId, int parentId)
	{
		View v = inflate(context, layoutId);
		((ViewGroup)context.findViewById(parentId)).addView(v);
		return v;
	}

	// ____________________________________________________________________________________
	public static boolean hasPhysicalKeyboard(Context context)
	{
		int keyboard = context.getResources().getConfiguration().keyboard;
		return keyboard == Configuration.KEYBOARD_QWERTY;
	}
	
	// ____________________________________________________________________________________
	public static void showKeyboard(final Context context, final View input)
	{
		// Never explicitly open soft keyboard if physical keyboard is present
		if(!hasPhysicalKeyboard(context))
		{
			input.post(new Runnable()
			{
				public void run()
				{
					// Use the modern WindowInsetsController API on API 30+.
					// showSoftInput() can produce misaligned touch targets on modern
					// Android (especially Samsung devices), causing dead zones on the
					// left portion of the keyboard. WindowInsetsController avoids this.
					WindowInsetsControllerCompat controller = ViewCompat.getWindowInsetsController(input);
					if (controller != null) {
						controller.show(WindowInsetsCompat.Type.ime());
					} else {
						// Fallback for edge cases where the view has no window
						InputMethodManager imm = (InputMethodManager)context.getSystemService(Context.INPUT_METHOD_SERVICE);
						imm.showSoftInput(input, InputMethodManager.SHOW_IMPLICIT);
					}
				}
			});
		}
	}

	// ____________________________________________________________________________________
	public static void hideKeyboard(Context context, EditText input)
	{
		InputMethodManager imm = (InputMethodManager)context.getSystemService(Context.INPUT_METHOD_SERVICE);
		imm.hideSoftInputFromWindow(input.getWindowToken(), 0);
	}

	// ____________________________________________________________________________________
	public static void hideKeyboard(Context context, View view)
	{
		view.setFocusable(false);
		InputMethodManager imm = (InputMethodManager)context.getSystemService(Context.INPUT_METHOD_SERVICE);
		imm.hideSoftInputFromWindow(view.getWindowToken(), 0);
	}
	
	// ____________________________________________________________________________________
	public static int parseInt(String string, int def)
	{
		try
		{
			return Integer.parseInt(string);
		}
		catch(NumberFormatException e)
		{
		}
		return def;
	}

	// ____________________________________________________________________________________
	public static void copy(InputStream is, OutputStream os) throws IOException
	{
		byte[] buf = new byte[10240];
		int read;
		while((read = is.read(buf)) != -1)
			os.write(buf, 0, read);
	}
}
