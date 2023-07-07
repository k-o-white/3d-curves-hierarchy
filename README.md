<h1>3D Curves Hierarchy</h1>
<p>This is a console application that supports three types of 3D curves: circles, ellipses and 3D helixes. It allows to 
calculate 3D point and first derivative per parameter along the curve for each type.</p>
<h2>How to build and run</h2>
<p>To build and run this app you need:</p>
<ul>
    <li>C++17 compliant compiler</li>
    <li>CMake build system (3.23 or higher)</li>
    <li>OpenMP library</li>
</ul>
<ul>
    <li>
        Clone this repository:
        <blockquote>
            <code>git clone https://github.com/k-o-white/3d-curves-hierarchy.git</code>
            <code>cd 3d-curves-hierarchy</code>
        </blockquote>
    <li>
        Create folder for building app and go to it:
        <blockquote>
            <code>mkdir build</code><br>
            <code>cd build</code>
        </blockquote>
    </li>
    <li>
        Build project (for example, if you use MinGW):
        <blockquote>
            <code>cmake -G "MinGW Makefiles" ..</code><br>
            <code>mingw32-make</code>
        </blockquote>
    </li>
    <li>
        Run the app:
        <blockquote>
            <code>cd src</code><br>
            <code>start 3DCurvesHierarchy.exe</code>
        </blockquote>
    </li>
</ul>


